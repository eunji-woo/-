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
				System.out.println("1.�Է� 2.��ȸ 3.���� 4.����  5.������");
				String menu_no = scanner.nextLine(); //��ȣ�� �ƴ� �ѱ��� �Էµ� ��� ����ó���� �ϱ� ���ؼ� ���ڿ��� �Է��� �޴´�
				
				
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
				else //1, 2, 3, 4, 5�� �ƴ� �ٸ� ���� �ԷµǾ��� ��쿡 ���� ����ó��
					System.out.println("�ùٸ� �޴��� �������ּ���. ");
				
			} //while }
		}
		catch(Exception e) { //����Ǵ� ������ �� ó�������� Ȥ�ó� ���� �������� ���� ������ �� ��쿡 ���� ����ó�� �Ф�
			System.out.println("�������� ���� ������ �߻��Ͽ����ϴ�.");
			e.getMessage();
		}		
	}

}


