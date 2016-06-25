<!doctype html>
<HTML lang="ja">
	<HEAD>
		<meta charset="utf-8">
		<TITLE>住所録</TITLE>
	</HEAD>
	<BODY>
		<?php
		$server	= "localhost";
		$mysqluser = "ds113193t";
		$mysqlpasswd = "19930522";
		
		$link = mysql_connect($server,$mysqluser,$mysqlpasswd);
		
		if(!$link){
				die("MySQLに接続できませんでした。".mysql_error());
		}
		
		mysql_query("SET CHARACTER SET utf8",$link);
		
		mysql_select_db("ds113193t_greeting_cards",$link);
		?>
		
		<?php
		$query = "SELECT ALL name,postal_code,address1,address2,phone FROM address_book;";
		$results = mysql_query($query,$link);
		?>
		
		<?php
		while($row = mysql_fetch_array($results,MYSQL_ASSOC)){
			print("<p>");
			print("氏名:".$row["name"]."<br>\n");
			print("〒".$row["postal_code"]."<br>\n");
			print("住所:".$row["address1"]."(".$row["address2"].")<br>\n");
			print("電話:".$row["phone"]."<br>\n</p>");
		}
		?>
		
		<?php
		mysql_close($link);
		?>
	</BODY>
</HTML>