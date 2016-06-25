using UnityEngine;
using System.Collections;
using System.IO.Ports;
using System.Threading;

public enum ZigResolution
{
    QQVGA_160x120,
    QVGA_320x240,
    VGA_640x480,
}

public class ResolutionData
{
    protected ResolutionData(int width, int height)
    {
        Width = width;
        Height = height;
    }
    public int Width { get; private set; }
    public int Height { get; private set; }
    public static ResolutionData FromZigResolution(ZigResolution res)
    {
        switch (res) {
            default: //fallthrough - default to QQVGA
            case ZigResolution.QQVGA_160x120:
                return new ResolutionData(160, 120);
            case ZigResolution.QVGA_320x240:
                return new ResolutionData(320, 240);
            case ZigResolution.VGA_640x480:
                return new ResolutionData(640, 480);
        }
        
    }
}

public class ZigDepthViewer : MonoBehaviour {
    public Renderer target;
    public ZigResolution TextureSize = ZigResolution.QQVGA_160x120;
    public Color32 BaseColor = Color.yellow;
    public bool UseHistogram = true;
    Texture2D texture;
    ResolutionData textureSize;

	public GameObject frame; //use this for getting frame position.
	public GameObject breathmeter; //use this for displaying breath.
	public float depthtmp;

	//Arduino
	//public static SerialPort sp = new SerialPort("/dev/tty.usbmodemFA131", 9600);

    float[] depthHistogramMap;
    Color32[] depthToColor;
    Color32[] outputPixels;
    public int MaxDepth = 10000; //DO NOT MODIFY IN RUNTIME!!
	// Use this for initialization
	void Start () {
		frame = GameObject.FindGameObjectWithTag ("frame");
		breathmeter = GameObject.FindGameObjectWithTag ("breath");

//		sp.Open();
//		sp.ReadTimeout = 1;

        if (target == null) {
            target = GetComponent<Renderer>();
        }
        textureSize = ResolutionData.FromZigResolution(TextureSize);
        texture = new Texture2D(textureSize.Width, textureSize.Height);
        texture.wrapMode = TextureWrapMode.Clamp;
        depthHistogramMap = new float[MaxDepth];
        depthToColor = new Color32[MaxDepth];
        outputPixels = new Color32[textureSize.Width * textureSize.Height];
        ZigInput.Instance.AddListener(gameObject);

        if (null != target) {
            target.material.mainTexture = texture;
        }
	}

    void UpdateHistogram(ZigDepth depth)
    {
        int i, numOfPoints = 0;

        System.Array.Clear(depthHistogramMap, 0, depthHistogramMap.Length);
        short[] rawDepthMap = depth.data;

		// resolution is  640 * 480.
		// rawDepthMap is from 0 to  307199.
		// rawDepthMap's value is distance from kinect.(black screen means 0.)

//		for(int j = 300000;j< 310000;j++){
//			Debug.Log (j + ":" + rawDepthMap[j]);
//		}

		//153920 is the center of image.
		int center = (int)((frame.transform.position.x + 4.54) * 100 + (frame.transform.position.y * (-1) + 3.44) * 100 * 640);
		//Debug.Log (center + ":" + rawDepthMap[center]);

		float sumdepth = 0;
		//Sum up 900 pixels.
		int count = 0;
		for (int j = center - (30 / 2 * 640); j < center + (30 / 2 * 640); j+=640) {
			for (int k = j - (30 / 2); k < j + (30 / 2); k++) {
				if (rawDepthMap [k] != 0) {
					sumdepth = sumdepth + rawDepthMap [k];
					count += 1;
				}
			}
		}
		Debug.Log (count);
//		float average = sumdepth / count;
//		sumdepth = 0;
//		count = 0;
//		for (int j = center - (30 / 2 * 640); j < center + (30 / 2 * 640); j+=640) {
//			for (int k = j - (30 / 2); k < j + (30 / 2); k++) {
//				if (Mathf.Abs(rawDepthMap [k] - average) < 50) {
//					sumdepth = sumdepth + rawDepthMap [k];
//					count += 1;
//				}
//			}
//		}
//		sumdepth = sumdepth / count;
		//Debug.Log (rawDepthMap [153920]);
		//Debug.Log (Mathf.Log(sumdepth) - 6);
		//Debug.Log (count);
//		long average = sumdepth / 900;
//		Debug.Log (average);

		Color color = Color.black;
		//depthtmp != null && 
		if (count == 900) {
			//Debug.Log (((Mathf.Log(depthtmp)-Mathf.Log(sumdepth))) * 150);
			if ((((Mathf.Log (depthtmp) - Mathf.Log (sumdepth))) * 150 > 0.09 && ((Mathf.Log (depthtmp) - Mathf.Log (sumdepth))) * 150 < 1.2) 
				|| (((Mathf.Log (depthtmp) - Mathf.Log (sumdepth))) * 150 < -0.09 && ((Mathf.Log (depthtmp) - Mathf.Log (sumdepth))) * 150 > -1.2) ) {
				//Debug.Log ("Breath:" + ((Mathf.Log (depthtmp) - Mathf.Log (sumdepth))) * 150);
			}

			color.r = Mathf.Abs((Mathf.Log(depthtmp)-Mathf.Log(sumdepth))) * 150;
			//Debug.Log (((Mathf.Log (depthtmp) - Mathf.Log (sumdepth))) * 150);
//			if ((Mathf.Log (depthtmp) - Mathf.Log (sumdepth)) * 150 > 0.06 && ((Mathf.Log (depthtmp) - Mathf.Log (sumdepth))) * 150 < 0.3) {
//				sendIN ();
//				Debug.Log ("Breathin:" + ((Mathf.Log (depthtmp) - Mathf.Log (sumdepth))) * 150);
//			} else if (((Mathf.Log (depthtmp) - Mathf.Log (sumdepth))) * 150 < -0.06 && ((Mathf.Log (depthtmp) - Mathf.Log (sumdepth))) * 150 > -0.3) {
//				sendOUT ();
//				Debug.Log ("Breathout:" + ((Mathf.Log (depthtmp) - Mathf.Log (sumdepth))) * 150);
//			}
			if ((Mathf.Log (depthtmp) - Mathf.Log (sumdepth)) * 150 > 0.07) {
				//sendIN ();
				color.r = Mathf.Abs((Mathf.Log(depthtmp)-Mathf.Log(sumdepth))) * 150;
				Debug.Log ("Breathin:" + ((Mathf.Log (depthtmp) - Mathf.Log (sumdepth))) * 150);
			} else if (((Mathf.Log (depthtmp) - Mathf.Log (sumdepth))) * 150 < -0.07) {
				//sendOUT ();
				color.b = Mathf.Abs((Mathf.Log(depthtmp)-Mathf.Log(sumdepth))) * 150;
				Debug.Log ("Breathout:" + ((Mathf.Log (depthtmp) - Mathf.Log (sumdepth))) * 150);
			}
			depthtmp = sumdepth;
 		}

		//Debug.Log (color);

		breathmeter.GetComponent<Renderer> ().material.color = color;




        int depthIndex = 0;
        // assume only downscaling
        // calculate the amount of source pixels to move per column and row in
        // output pixels
        int factorX = depth.xres/textureSize.Width;
        int factorY = ((depth.yres / textureSize.Height) - 1) * depth.xres;
        for (int y = 0; y < textureSize.Height; ++y, depthIndex += factorY) {
            for (int x = 0; x < textureSize.Width; ++x, depthIndex += factorX) {
                short pixel = rawDepthMap[depthIndex];
                if (pixel != 0) {
                    depthHistogramMap[pixel]++;
                    numOfPoints++;
                }
            }
        }
        depthHistogramMap[0] = 0;
        if (numOfPoints > 0) {
            for (i = 1; i < depthHistogramMap.Length; i++) {
                depthHistogramMap[i] += depthHistogramMap[i - 1];
            }
            depthToColor[0] = Color.black;
            for (i = 1; i < depthHistogramMap.Length; i++) {
                float intensity = (1.0f - (depthHistogramMap[i] / numOfPoints));
                //depthHistogramMap[i] = intensity * 255;
                depthToColor[i].r = (byte)(BaseColor.r * intensity);
                depthToColor[i].g = (byte)(BaseColor.g * intensity);
                depthToColor[i].b = (byte)(BaseColor.b * intensity);
                depthToColor[i].a = 255;//(byte)(BaseColor.a * intensity);
            }
        }
        

    }

    void UpdateTexture(ZigDepth depth)
    {
        short[] rawDepthMap = depth.data;
        int depthIndex = 0;
        int factorX = depth.xres / textureSize.Width;
        int factorY = ((depth.yres / textureSize.Height) - 1) * depth.xres;
        // invert Y axis while doing the update
        for (int y = textureSize.Height - 1; y >= 0 ; --y, depthIndex += factorY) {
            int outputIndex = y * textureSize.Width;
            for (int x = 0; x < textureSize.Width; ++x, depthIndex += factorX, ++outputIndex) {
                outputPixels[outputIndex] = depthToColor[rawDepthMap[depthIndex]];
            }
        }
        texture.SetPixels32(outputPixels);
        texture.Apply();
    }

    void Zig_Update(ZigInput input)
    {
        if (UseHistogram) {
            UpdateHistogram(ZigInput.Depth);
        }
        else {
            //TODO: don't repeat this every frame
            depthToColor[0] = Color.black;
            for (int i = 1; i < MaxDepth; i++) {
                float intensity = 1.0f - (i/(float)MaxDepth);
                //depthHistogramMap[i] = intensity * 255;
                depthToColor[i].r = (byte)(BaseColor.r * intensity);
                depthToColor[i].g = (byte)(BaseColor.g * intensity);
                depthToColor[i].b = (byte)(BaseColor.b * intensity);
                depthToColor[i].a = 255;//(byte)(BaseColor.a * intensity);
            }
        }
        UpdateTexture(ZigInput.Depth);
    }

    void OnGUI() {
        if (null == target) {
            GUI.DrawTexture(new Rect(Screen.width - texture.width - 10, Screen.height - texture.height - 10, texture.width, texture.height), texture);
        }
    }

//	void OnApplicationQuit(){
//		sp.Close ();
//	}
//
//
//	public static void sendIN(){
//		sp.Write("h");
//	}
//
//	public static void sendOUT(){
//		sp.Write("g");
//	}
}


