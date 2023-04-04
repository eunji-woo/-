package final_project;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class TaskExample {
	public static void main(String[] args) {
		try {
			Scanner scanner = new Scanner(System.in);
			List<Task> taskList = new ArrayList<>();
			
			while(true) {
				System.out.println("1.입력 2.조회 3.수정 4.삭제  5.끝내기");
				String menu_no = scanner.nextLine(); //번호가 아닌 한글이 입력될 경우 예외처리를 하기 위해서 문자열로 입력을 받는다
				
				
				if(menu_no.equals("1")) 
					Task.insert_todo(taskList);
				
				else if(menu_no.equals("2"))
					Task.print_todo(taskList);
					
				else if(menu_no.equals("3"))
					Task.update_todo(taskList);
				
				else if(menu_no.equals("4")) 
					Task.remove_todo(taskList);
				
				else if(menu_no.equals("5")) {
					Task.end_todo();
					break;
				}
				else //1, 2, 3, 4, 5가 아닌 다른 수가 입력되었을 경우에 대한 오류처리
					System.out.println("올바른 메뉴를 선택해주세요. ");
				
			} //while }
		}
		catch(Exception e) { //예상되는 오류는 다 처리했지만 혹시나 내가 예상하지 못한 오류가 날 경우에 대한 오류처리 ㅠㅠ
			System.out.println("예상하지 못한 오류가 발생하였습니다.");
			e.getMessage();
		}		
	}

}


