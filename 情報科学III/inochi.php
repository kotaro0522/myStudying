<!doctype html>
<HTML lang="ja">
	<HEAD>
		<meta charset="utf-8">
		<TITLE>命</TITLE>
	</HEAD>
	<BODY>
		<?php
			echo '一回目に入力された文字列は:「' . htmlspecialchars($_POST["kekka"]) . '」でした。' ;
			print("<BR>\n");
			echo '二回目に入力された文字列は:「' . htmlspecialchars($_POST["life"]) . '」でした。';
		?>
	</BODY>
</HTML>