<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<%@ page import="java.util.*, ch14.*"%>
<jsp:useBean id="memberMgr" class="ch14.MemberMgr" />
<html>
<head>
</head>
<body>
<%
  request.setCharacterEncoding("EUC-KR");
  String id = session.getAttribute("idKey").toString();
  String pwd = request.getParameter("pwd");
  String url = "startCh14.jsp";
  String msg = "È¸¿ø Å»Åð ¼º°ø!";
  
  boolean result = memberMgr.loginMember(id, pwd);
  if(result){
	session.invalidate();
	memberMgr.deleteMemberList(id);
  }
  
  else{
	  msg = "ºñ¹Ð¹øÈ£°¡ Æ²·È½À´Ï´Ù.";
	  url = "memberDelete.jsp";
  }
 %>
 
<script>
	alert("<%=msg%>");	
	top.document.location.reload(); 
	location.href="<%=url%>";
</script>
</body>
</html>