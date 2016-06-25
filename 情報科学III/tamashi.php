<!doctype html>
<HTML lang="ja">
	<HEAD>
		<meta charset="utf-8">
		<TITLE>魂</TITLE>
	</HEAD>
	<BODY>
		<?php
			echo '「' . htmlspecialchars($_POST["soul"]) . '！！！！！！！！」';
		?>
		<BR>
		<FORM ACTION="inochi.php" METHOD="POST">
			命よりも大切なものを入力してください。<BR>
			<INPUT TYPE="hidden" NAME="kekka" VALUE="<?php echo $_POST["soul"]; ?>">
			<INPUT TYPE="TEXT" NAME="life" VALUE="愛">
			<INPUT TYPE="SUBMIT" NAME="submit4" VALUE="OK">
			<INPUT TYPE="RESET" NAME="reset4" VALUE="リセット">
		</FORM>
	</BODY>
</HTML>