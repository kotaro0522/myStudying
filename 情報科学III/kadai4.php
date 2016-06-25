<html lang="ja">
<head>
<meta charset="utf-8">
<title>kadai4</title>
</head>
<body>
		
<?php
		$s = "ATCTTTTTCGGCTTTTTTTAGTATCCACAG"; // 文字列は適当に与える!

		echo($s);
		print("の各文字の出現回数は、\n\n");

		$array=str_split($s);

		//print_r($array);
		
		$array_value = array_count_values($array);

		//print_r($array_value);
		
		arsort($array_value);
		
		$check=$array_value;
		rsort($check);
		
		$max=count($check);
		
		$kaisu=1;
		
		for($i=1;$i<=$max;$i++){
			$k=$i-1;//添字に$i-iを入れると上手くいかなかったため
			$hikaku1=$check[$k];
			$hikaku2=$check[$i];
			if($hikaku1==$hikaku2){//要素が最大のものの数を求める。
				$kaisu++;
			}
			else goto end;
		}
		
	  end:
		
		$j=0;
			
			foreach($array_value as $words=>$figure){
				$j++;
				print("文字：$words  回数：$figure\n");
			if($j<=$kaisu){//上で求めた回数だけ表示させる。
				print("これは出現回数が最大の文字です。\n");
			}
			}
			
		?>	
		
</body>		
</html>