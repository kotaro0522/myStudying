using UnityEngine;
using System.Collections;

public class FrameController : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKey(KeyCode.UpArrow)) {
			transform.position = new Vector3(transform.position.x, transform.position.y + 0.05f, transform.position.z);
		} else if(Input.GetKey(KeyCode.DownArrow)) {
			transform.position = new Vector3(transform.position.x, transform.position.y - 0.05f, transform.position.z);
		} else if(Input.GetKey(KeyCode.LeftArrow)) {
			transform.position = new Vector3(transform.position.x - 0.05f, transform.position.y, transform.position.z);
		} else if(Input.GetKey(KeyCode.RightArrow)) {
			transform.position = new Vector3(transform.position.x + 0.05f, transform.position.y, transform.position.z);
		} 
	
	}
}
