<!doctype html>
<HTML lang="ja">
	<HEAD>
		<meta charset="utf-8">
		<TITLE>住所録</TITLE>
	</HEAD>
	<BODY>
		<?php
		//最初に変数の中に各種の情報を入れとく
		$server	= "localhost";
		$mysqluser = "ds113193t";
		$mysqlpasswd = "19930522";
		
		//MySQLに接続させる。成功したらMySQLリンクIDを、失敗したらFALSEを返す。
		$link = mysql_connect($server,$mysqluser,$mysqlpasswd);
		
		//MySQLに接続できなかった場合($linkの値が0)
		if(!$link){
				die("MySQLに接続できませんでした。".mysql_error());
		}
		
		//文字コードの設定
		mysql_query("SET CHARACTER SET utf8",$link);
		
		//データベースの選択
		mysql_select_db("ds113193t_greeting_cards",$link);
		
		//データを登録
		$query = "INSERT INTO address_book SET name='htmlspecialchars($_POST["name"])', postal_code='htmlspecialchars($_POST["postal_code"])',  address1='htmlspecialchars($_POST["address1"])', address2='htmlspecialchars($_POST["address2"])', phone='htmlspecialchars($_POST["phone"])'; ";
		mysql_query($query,$link);
		?>
		
		<!-- MySQLを終了 -->
		<?php
		mysql_close($link);
		?>
		登録しました。
		<A Href="main.html">戻る</A>
	</BODY>
</HTML>