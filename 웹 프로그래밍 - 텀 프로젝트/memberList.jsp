<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%@ page import="java.util.*, ch14.*"%>
<jsp:useBean id="memberMgr" class="ch14.MemberMgr" />
<html>
<head>
<meta charset="UTF-8">
<title>회원 목록</title>
</head>
<body>
<table bordercolor="#0000ff" border="1">
<tr>
   <td><strong>id</strong></td>
   <td><strong>pwd</strong></td>
   <td><strong>name</strong></td>
   <td><strong>gender</strong></td>
   <td><strong>birthday</strong></td>
   <td><strong>email</strong></td>
   <td><strong>zipcode</strong></td>
   <td><strong>address</strong></td>
   <td><strong>hobby</strong></td>
   <td><strong>job</strong></td>	
</tr>

<%
Vector<MemberBean> vlist = memberMgr.getMemberList();
for(int i=0; i<vlist.size(); i++){
	MemberBean memberBean =vlist.get(i);
%>
<tr>
<td><%=memberBean.getId()%></td>
<td><%=memberBean.getPwd()%></td>
<td><%=memberBean.getName()%></td>
<td><%
if(memberBean.getGender().equals("1"))
	out.print("남자");
else
	out.print("여자");
%></td>
<td><%=memberBean.getBirthday()%></td>
<td><%=memberBean.getEmail()%></td>
<td><%=memberBean.getZipcode()%></td>
<td><%=memberBean.getAddress()%></td>
<td><% 
String hobby[] = memberBean.getHobby();
String lists[] = { "인터넷 ", "여행 ", "게임 ", "영화 ", "운동 " };

for (int a = 0; a < hobby.length; a++) {
	if(hobby[a].equals("1"))
		out.print(lists[a]);
}
%></td>
<td><%=memberBean.getJob()%></td>
</tr>
<%
   }
%>
</table>
</body>
</html>