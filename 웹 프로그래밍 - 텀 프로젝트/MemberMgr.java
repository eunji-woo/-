package ch14;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.Vector;

public class MemberMgr {

	private DBConnectionMgr pool;

	public MemberMgr() {
		try {
			pool = DBConnectionMgr.getInstance();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
		
	// ID 중복확인
	public boolean checkId(String id) {
		Connection con = null;
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		String sql = null;
		boolean flag = false;
		try {
			con = pool.getConnection();
			sql = "select id from tblMember where id = ?";
			pstmt = con.prepareStatement(sql);
			pstmt.setString(1, id);
			flag = pstmt.executeQuery().next();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			pool.freeConnection(con, pstmt, rs);
		}
		return flag;
	}

	// 우편번호 검색
	public Vector<ZipcodeBean> zipcodeRead(String area3) {
		Connection con = null;
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		String sql = null;
		Vector<ZipcodeBean> vlist = new Vector<ZipcodeBean>();
		try {
			con = pool.getConnection();
			sql = "select * from tblZipcode where area3 like ?";
			pstmt = con.prepareStatement(sql);
			pstmt.setString(1, "%" + area3 + "%");
			rs = pstmt.executeQuery();
			while (rs.next()) {
				ZipcodeBean bean = new ZipcodeBean();
				bean.setZipcode(rs.getString(1));
				bean.setArea1(rs.getString(2));
				bean.setArea2(rs.getString(3));
				bean.setArea3(rs.getString(4));
				vlist.addElement(bean);
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			pool.freeConnection(con, pstmt, rs);
		}
		return vlist;
	}

	// 회원가입
	public boolean insertMember(MemberBean bean) {
		Connection con = null;
		PreparedStatement pstmt = null;
		String sql = null;
		boolean flag = false;
		try {
			con = pool.getConnection();
			sql = "insert tblMember(id,pwd,name,gender,birthday,email,zipcode"
					+ ",address,hobby,job)values(?,?,?,?,?,?,?,?,?,?)";
			pstmt = con.prepareStatement(sql);
			pstmt.setString(1, bean.getId());
			pstmt.setString(2, bean.getPwd());
			pstmt.setString(3, bean.getName());
			pstmt.setString(4, bean.getGender());
			pstmt.setString(5, bean.getBirthday());
			pstmt.setString(6, bean.getEmail());
			pstmt.setString(7, bean.getZipcode());
			pstmt.setString(8, bean.getAddress());
			String hobby[] = bean.getHobby(); //ex)인터넷, 운동..(한글로 들어있음)
			char hb[] = { '0', '0', '0', '0', '0' };
			String lists[] = { "인터넷", "여행", "게임", "영화", "운동" };
			for (int i = 0; i < hobby.length; i++) {
				for (int j = 0; j < lists.length; j++) {
					if (hobby[i].equals(lists[j]))
						hb[j] = '1';
				}
			}
			pstmt.setString(9, new String(hb));
			pstmt.setString(10, bean.getJob());
			if (pstmt.executeUpdate() == 1)
				flag = true;
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			pool.freeConnection(con, pstmt);
		}
		return flag;
	}

	// 로그인
	public boolean loginMember(String id, String pwd) {
		Connection con = null;
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		String sql = null;
		boolean flag = false;
		try {
			con = pool.getConnection();
			sql = "select id from tblMember where id = ? and pwd = ?";
			pstmt = con.prepareStatement(sql);
			pstmt.setString(1, id);
			pstmt.setString(2, pwd);
			rs = pstmt.executeQuery();
			flag = rs.next();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			pool.freeConnection(con, pstmt, rs);
		}
		return flag;
	}
	
	
	
	
	//회원 목록 보기
		public Vector<MemberBean> getMemberList() {
			   Connection conn = null;
			   Statement stmt = null;
			   ResultSet rs = null;
			   Vector<MemberBean> vlist = new Vector<>();
			   try {
				   conn = pool.getConnection();
		           String sql = "select * from tblMember";
		           stmt = conn.createStatement();
		           rs = stmt.executeQuery(sql);
				  while (rs.next()) {
		             MemberBean membean = new MemberBean();
		             membean.setId (rs.getString("id"));
		             membean.setPwd (rs.getString("pwd"));
		             membean.setName (rs.getString("name"));
		             membean.setGender (rs.getString("gender"));
		             membean.setBirthday (rs.getString("birthday"));
		             membean.setEmail (rs.getString("email"));
		             membean.setZipcode (rs.getString("zipcode"));
		             membean.setAddress (rs.getString("address"));
					 String hobbys[] = new String[5];
						String hobby = rs.getString("hobby");
						for (int i = 0; i < hobbys.length; i++) {
							hobbys[i] = hobby.substring(i, i + 1);
						}
						membean.setHobby(hobbys);
						membean.setJob (rs.getString("job"));
		 			 vlist.add(membean);
		          }
		       } catch (Exception e) {
		    	   e.printStackTrace();
		       } finally {
			      pool.freeConnection(conn);
		       }
		       return vlist;
		 }
	
	
	//회원 탈퇴
	public void deleteMemberList(String id){
        Connection conn=null;
        PreparedStatement pstmt =null;
        try{
            conn = pool.getConnection();
            String sql = "delete from tblMember where id=?";
            pstmt =conn.prepareStatement(sql);
            pstmt.setString(1, id);
            pstmt.executeUpdate();
        }catch(Exception e){
        	e.printStackTrace();
        }finally{
        	pool.freeConnection(conn);
        }
	}
	
	//이름 가져오는 메소드
		public String getName(String id){
			Connection conn = null;
			PreparedStatement pstmt = null;
			ResultSet rs = null;
			String sql = null;
			String login_name = null;
	        try{
	            conn = pool.getConnection();
	            sql = "select * from tblMember where id=?";
				pstmt = conn.prepareStatement(sql);
				pstmt.setString(1, id);
				rs = pstmt.executeQuery();
				rs.next();
				login_name = rs.getString("name");
	        }catch(Exception e){
	        	e.printStackTrace();
	        }finally{
	        	pool.freeConnection(conn);
	        }
	        return login_name;
		}
		
	/*************
	 * ch17 필요한 메소드
	 * ************/

	// 회원정보가져오기
	public MemberBean getMember(String id) {
		Connection con = null;
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		MemberBean bean = null;
		try {
			con = pool.getConnection();
			String sql = "select * from tblMember where id = ?";
			pstmt = con.prepareStatement(sql);
			pstmt.setString(1, id);
			rs = pstmt.executeQuery();
			if (rs.next()) {
				bean = new MemberBean();
				bean.setId(rs.getString("id"));
				bean.setPwd(rs.getString("pwd"));
				bean.setName(rs.getString("name"));
				bean.setGender(rs.getString("gender"));
				bean.setBirthday(rs.getString("birthday"));
				bean.setEmail(rs.getString("email"));
				bean.setZipcode(rs.getString("zipcode"));
				bean.setAddress(rs.getString("address"));
				String hobbys[] = new String[5];
				String hobby = rs.getString("hobby");// 01001
				for (int i = 0; i < hobbys.length; i++) {
					hobbys[i] = hobby.substring(i, i + 1);
				}
				bean.setHobby(hobbys);
				bean.setJob(rs.getString("job"));
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			pool.freeConnection(con);
		}
		return bean;
	}

	// 회원정보수정
	public boolean updateMember(MemberBean bean) {
		Connection con = null;
		PreparedStatement pstmt = null;
		boolean flag = false;
		try {
			con = pool.getConnection();
			String sql = "update tblMember set pwd=?, name=?, gender=?, birthday=?,"
					+ "email=?, zipcode=?, address=?, hobby=?, job=? where id = ?";
			pstmt = con.prepareStatement(sql);
			pstmt.setString(1, bean.getPwd());
			pstmt.setString(2, bean.getName());
			pstmt.setString(3, bean.getGender());
			pstmt.setString(4, bean.getBirthday());
			pstmt.setString(5, bean.getEmail());
			pstmt.setString(6, bean.getZipcode());
			pstmt.setString(7, bean.getAddress());
			char hobby[] = { '0', '0', '0', '0', '0' };
			if (bean.getHobby() != null) {
				String hobbys[] = bean.getHobby();
				String list[] = { "인터넷", "여행", "게임", "영화", "운동" };
				for (int i = 0; i < hobbys.length; i++) {
					for (int j = 0; j < list.length; j++)
						if (hobbys[i].equals(list[j]))
							hobby[j] = '1';
				}
			}
			pstmt.setString(8, new String(hobby));
			pstmt.setString(9, bean.getJob());
			pstmt.setString(10, bean.getId());
			int count = pstmt.executeUpdate();
			if (count > 0)
				flag = true;
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			pool.freeConnection(con, pstmt);
		}
		return flag;
	}
}