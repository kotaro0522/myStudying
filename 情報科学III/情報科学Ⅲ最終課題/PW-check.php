<html>
<head>
	<meta http-equiv="CONTENT-TYPE"	CONTENT="text/html;CHARSET=UTF-8">
	<title>Sample for Password</title>
</head>
<body>
<?php
$name = $_POST["name"];
$password = $_POST["password"];
if($name == "" || $password == ""){
	die("名前とパスワードの両方を入力してください。");
}

require('PW-dbaccess.php');

//	パスワードのチェック
$sql = "SELECT * FROM users WHERE name = '$name' AND password = PASSWORD('$password');";
$result = mysql_query($sql,$link);
if($result == FALSE){
	echo mysql_error();
	die("<br>SQLの実行に失敗しました。");
}
$num = mysql_num_rows($result);
if($num == 0) echo "利用者の認証に失敗しました。";
else echo "利用者の認証に成功しました。";
?>
<br>
<A Href="new.html">アドレス登録</A>
<br>
<A Href="main.html">戻る</A>
</body>
</html>
