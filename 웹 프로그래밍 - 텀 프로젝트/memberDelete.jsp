<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<%@ page import="java.util.*, ch14.*"%>
<html>
<head>
<meta charset="EUC-KR">
<title>회원 탈퇴</title>
</head>
<body>
<form action="memberDeletePro.jsp" method="post">
비밀번호: <input type="password" name="pwd"><br>
<input type="submit" value="회원 탈퇴"><br>
</form>
</body>
</html>