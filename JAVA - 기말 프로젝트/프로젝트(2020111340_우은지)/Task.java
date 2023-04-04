package final_project;

import java.util.List;
import java.util.Scanner;

public class Task implements Priority {
	private String taskName;
	private int taskTime;
	private int priority;
	
	static Scanner scanner = new Scanner(System.in);
	
	public Task(String taskName, int taskTime, int priority)
	{
		this.taskName = taskName;
		this.taskTime = taskTime;
		this.priority = priority;
	}

	public int getPriority() {
		return priority;
	}

	public void setPriority(int priority) {
		this.priority = priority;
	}
	
    static public void insert_todo(List<Task> taskList) { //1.�Է� �޼ҵ�-------------------------------------
    	System.out.println("�ؾ��� ���� �̸��� �Է����ּ���.");
		String insert_name = scanner.nextLine();
		System.out.println("�ؾ��� ���� �ҿ�ð��� �Է����ּ���.");
		int insert_tasktime =  Integer.parseInt(scanner.nextLine());
		System.out.println("�ؾ��� ���� �켱������ �Է����ּ���.");
		int insert_priority;
		while(true) { // �켱���� ���� ���� ���� ���� �Է� �����ϵ��� �ϴ� while��
			insert_priority = Integer.parseInt(scanner.nextLine());
			
			if(insert_priority>0) {
				break;
			}
			else
				System.out.print("���� ������ �Է����ּ���.");
		}
		if(insert_priority > taskList.size()) //���� �Է¹��� �켱������ ���� �ִ� �׸��� ������ ū ���
			taskList.add(taskList.size(), new Task(insert_name, insert_tasktime, taskList.size()+1)); //list�� �� �ڿ� �׸��� �߰�
		else {//�켱������ ���� �ִ� �׸� ������ ���ų� ���� ���
			for(int h=insert_priority-1; h<taskList.size(); h++) //�߰��Ǵ� �׸��� �켱������ ������ �ִ� �׸�� ��ġ�� ��쿡 ���� ó��
				taskList.get(h).setPriority(taskList.get(h).getPriority()+1);
			taskList.add(insert_priority-1, new Task(insert_name, insert_tasktime, insert_priority)); //�켱������ �Է��� �켱������ �������ְ� list���� �Է��� �켱�������� 1���� �ε����� ����
		}
    }
	
    public void printTask() //��ȸ �޴��� �޼ҵ忡�� ����ϱ� ���� ��
	{
		System.out.print("�̸� = " + this.taskName);
		System.out.print(", �ҿ� �ð� = " + this.taskTime);
		System.out.println(", �켱 ����  = " + this.priority);
	}

    static public void print_todo(List<Task> taskList) { //2.��ȸ �޼ҵ�--------------------------------------
		for(int i=0; i<taskList.size(); i++) {
			System.out.print("No." + (i+1) + " - ");
			taskList.get(i).printTask();
		}
	}
    
    static public void update_todo(List<Task> taskList) { //3.���� �޼ҵ�-------------------------------------
		int update_no;
		if (taskList.size() == 0) { //���� �߰��� �׸��� ���� ��쿡 ���� ����ó��
			System.out.println("������ �� �ִ� �׸��� �����ϴ�.");
			return;
		}
		print_todo(taskList);
		System.out.println("������ ��ȣ��  �Է����ּ���.");
		while(true) { //��ȿ�� ��ȣ�� �Է��� ������ �ݺ�
			update_no = scanner.nextInt();
			
			if(update_no <= taskList.size() && update_no >=1) { //��ȿ�� ��ȣ�� �Է��ϸ� while�� ����
				break;
			}
			else
				System.out.println("������ ��ȣ�� �ٽ� �Է����ּ���.");
			
		}

		System.out.println("������ �켱������ �Է����ּ���.");
		int update_priority;
		while(true) { // �켱���� ���� ���� ���� ���� �Է� �����ϵ��� �ϴ� while��
			update_priority = scanner.nextInt();
			
			if(update_priority>0) {
				break;
			}
			else
				System.out.print("���� ������ �Է����ּ���.");
		}
		if(update_priority > taskList.size()) { //������ �켱������ ���� �׸� �������� ū ��쿣 list �������� �׸� �߰��ǰ� ��
			Task update_task = taskList.get(update_no-1); //�����ϱ� �� �׸��� ��������� �����ص�
			taskList.remove(update_no-1); //�ϴ� ������ �켱������ �����صΰ� �������� �ٽ� �߰���
			//�켱������ �����Ǹ� �ٸ� �׸���� �켱������ �����Ǿ���� �� �ؿ� if, else���� �� �κ��� ������ ��
			if(update_no==1) { //������ �켱������ ���� �׸� �������� Ŀ�� list �������� �׸� �߰��Ǵ� ��쿡 1�� �׸��� �����ϸ� 
				for(int h=0; h<taskList.size(); h++)  //������ �켱������ ��� �����ص����ϱ� list�� ��ü �׸��� �켱������ -1�� ����
				taskList.get(h).setPriority(taskList.get(h).getPriority()-1);
			}
			else { //������ �켱������ ���� �׸� �������� Ŀ�� list �������� �׸� �߰��Ǵ� ��쿡 1�� �׸��� �ƴ� �ٸ� �׸��� �����ϸ�
				for(int h=update_no-1; h<taskList.size(); h++)  //�����ϴ� ��ȣ�� �ε�������(update_no-1) ����Ʈ�� ������ �켱���� -1�� ���� 
					taskList.get(h).setPriority(taskList.get(h).getPriority()-1);
			}
			taskList.add(taskList.size(), new Task(update_task.taskName, update_task.taskTime, taskList.size()+1)); //list�� �� �������� �����߾��� �׸��� �켱���� �ٲ㼭 �ٽ� add
		}
		else { //������ �켱������ ���� �׸� �������� ���ų� ���� ���
			Task update_task = taskList.get(update_no-1); //�����ϱ� �� �׸��� ��������� �����ص�
			taskList.remove(update_no-1);  //�ϴ� ������ �켱������ �����صΰ� �������� �ٽ� �߰���
			if(update_no<=update_priority) { //������ ��ȣ�� ������ �켱���� ������ �۰ų� ���� ���
				for(int h=update_no-1; h<update_priority-1; h++)  //������ ��ȣ�� �ε�������(update_no-1) �ٽ� add�� �� �������� �켱������ -1�� ����
					taskList.get(h).setPriority(taskList.get(h).getPriority()-1);
			}
			else { //������ ��ȣ�� ������ �켱���� ������ ū ���
				for(int h=update_priority-1; h<update_no-1; h++)
					taskList.get(h).setPriority(taskList.get(h).getPriority()+1);
			}
			taskList.add(update_priority-1, new Task(update_task.taskName, update_task.taskTime, update_priority)); //������ ��ü �����ϰ� ���ο� �켱������ ���ο� ��ü �����ؼ� add
		}
    }
    
    static public void remove_todo(List<Task> taskList) { //4.���� �޼ҵ�------------------------------------
    	int remove_no;
    	
    	if (taskList.size() == 0) {
			System.out.println("������ �� �ִ� �׸��� �����ϴ�.");
			return;
		}
    	
    	print_todo(taskList);
		System.out.print("������ ��ȣ�� �Է����ּ���.");
		
    	while(true) { //�Էµ� ��ȣ�� ���� �׸� ��ȣ �߿� ���� ������ �ݺ��ϰ� �� (���� ��ȣ�� ���� ����ó��) 
    		remove_no = scanner.nextInt();
			
			if(remove_no <= taskList.size() && remove_no >=1) {
				break;
			}
			else
				System.out.print("������ ��ȣ�� ��ȣ�� �ٽ� �Է����ּ���.");
				
			
		}
    	taskList.remove(remove_no-1);
    	for(int h=remove_no-1; h<taskList.size(); h++) { //������ �׸� ������ �׸���� �켱���� 1�� ����
			taskList.get(h).setPriority(taskList.get(h).getPriority()-1);
		}
	}
	
    static public void end_todo() {
    	System.out.print("���α׷��� �����մϴ�.");
    }
	
}
