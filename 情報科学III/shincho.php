<!doctype html>
<HTML lang="ja">
	<HEAD>
		<meta charset="utf-8">
		<TITLE>身長</TITLE>
	</HEAD>
	<BODY>
		<?php
			echo 'あなたの身長は' . htmlspecialchars($_POST["tall"]/100) . 'mです。';
		?>
	</BODY>
</HTML>