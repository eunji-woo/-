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
	
    static public void insert_todo(List<Task> taskList) { //1.입력 메소드-------------------------------------
    	System.out.println("해야할 일의 이름을 입력해주세요.");
		String insert_name = scanner.nextLine();
		System.out.println("해야할 일의 소요시간을 입력해주세요.");
		int insert_tasktime =  Integer.parseInt(scanner.nextLine());
		System.out.println("해야할 일의 우선순위을 입력해주세요.");
		int insert_priority;
		while(true) { // 우선순위 값에 양의 정수 값만 입력 가능하도록 하는 while문
			insert_priority = Integer.parseInt(scanner.nextLine());
			
			if(insert_priority>0) {
				break;
			}
			else
				System.out.print("양의 정수를 입력해주세요.");
		}
		if(insert_priority > taskList.size()) //만약 입력받은 우선순위가 현재 있는 항목의 수보다 큰 경우
			taskList.add(taskList.size(), new Task(insert_name, insert_tasktime, taskList.size()+1)); //list의 맨 뒤에 항목을 추가
		else {//우선순위가 현재 있는 항목 개수랑 같거나 작은 경우
			for(int h=insert_priority-1; h<taskList.size(); h++) //추가되는 항목의 우선순위가 기존에 있던 항목과 겹치는 경우에 대한 처리
				taskList.get(h).setPriority(taskList.get(h).getPriority()+1);
			taskList.add(insert_priority-1, new Task(insert_name, insert_tasktime, insert_priority)); //우선순위는 입력한 우선순위로 설정해주고 list에는 입력한 우선순위보다 1작은 인덱스에 저장
		}
    }
	
    public void printTask() //조회 메뉴의 메소드에서 사용하기 위한 것
	{
		System.out.print("이름 = " + this.taskName);
		System.out.print(", 소요 시간 = " + this.taskTime);
		System.out.println(", 우선 순위  = " + this.priority);
	}

    static public void print_todo(List<Task> taskList) { //2.조회 메소드--------------------------------------
		for(int i=0; i<taskList.size(); i++) {
			System.out.print("No." + (i+1) + " - ");
			taskList.get(i).printTask();
		}
	}
    
    static public void update_todo(List<Task> taskList) { //3.수정 메소드-------------------------------------
		int update_no;
		if (taskList.size() == 0) { //아직 추가된 항목이 없을 경우에 대한 오류처리
			System.out.println("수정할 수 있는 항목이 없습니다.");
			return;
		}
		print_todo(taskList);
		System.out.println("수정할 번호를  입력해주세요.");
		while(true) { //유효한 번호를 입력할 때까지 반복
			update_no = scanner.nextInt();
			
			if(update_no <= taskList.size() && update_no >=1) { //유효한 번호를 입력하면 while문 종료
				break;
			}
			else
				System.out.println("수정할 번호를 다시 입력해주세요.");
			
		}

		System.out.println("수정할 우선순위를 입력해주세요.");
		int update_priority;
		while(true) { // 우선순위 값에 양의 정수 값만 입력 가능하도록 하는 while문
			update_priority = scanner.nextInt();
			
			if(update_priority>0) {
				break;
			}
			else
				System.out.print("양의 정수를 입력해주세요.");
		}
		if(update_priority > taskList.size()) { //수정할 우선순위가 현재 항목 개수보다 큰 경우엔 list 마지막에 항목 추가되게 함
			Task update_task = taskList.get(update_no-1); //삭제하기 전 항목의 멤버변수들 저장해둠
			taskList.remove(update_no-1); //일단 수정할 우선순위를 삭제해두고 마지막에 다시 추가함
			//우선순위가 수정되면 다른 항목들의 우선순위도 수정되어야함 이 밑에 if, else문이 그 부분을 구현한 것
			if(update_no==1) { //수정할 우선순위가 현재 항목 개수보다 커서 list 마지막에 항목 추가되는 경우에 1번 항목을 수정하면 
				for(int h=0; h<taskList.size(); h++)  //수정할 우선순위는 잠시 삭제해뒀으니까 list의 전체 항목의 우선순위를 -1씩 해줌
				taskList.get(h).setPriority(taskList.get(h).getPriority()-1);
			}
			else { //수정할 우선순위가 현재 항목 개수보다 커서 list 마지막에 항목 추가되는 경우에 1번 항목이 아닌 다른 항목을 수정하면
				for(int h=update_no-1; h<taskList.size(); h++)  //수정하는 번호의 인덱스부터(update_no-1) 리스트의 끝까지 우선순위 -1씩 해줌 
					taskList.get(h).setPriority(taskList.get(h).getPriority()-1);
			}
			taskList.add(taskList.size(), new Task(update_task.taskName, update_task.taskTime, taskList.size()+1)); //list의 맨 마지막에 삭제했었던 항목을 우선순위 바꿔서 다시 add
		}
		else { //수정할 우선순위가 현재 항목 개수보다 같거나 작은 경우
			Task update_task = taskList.get(update_no-1); //삭제하기 전 항목의 멤버변수들 저장해둠
			taskList.remove(update_no-1);  //일단 수정할 우선순위를 삭제해두고 마지막에 다시 추가함
			if(update_no<=update_priority) { //수정할 번호가 수정할 우선순위 값보다 작거나 같은 경우
				for(int h=update_no-1; h<update_priority-1; h++)  //수정될 번호의 인덱스부터(update_no-1) 다시 add될 곳 전까지의 우선순위를 -1씩 해줌
					taskList.get(h).setPriority(taskList.get(h).getPriority()-1);
			}
			else { //수정할 번호가 수정할 우선순위 값보다 큰 경우
				for(int h=update_priority-1; h<update_no-1; h++)
					taskList.get(h).setPriority(taskList.get(h).getPriority()+1);
			}
			taskList.add(update_priority-1, new Task(update_task.taskName, update_task.taskTime, update_priority)); //기존의 객체 삭제하고 새로운 우선순위로 새로운 객체 생성해서 add
		}
    }
    
    static public void remove_todo(List<Task> taskList) { //4.삭제 메소드------------------------------------
    	int remove_no;
    	
    	if (taskList.size() == 0) {
			System.out.println("삭제할 수 있는 항목이 없습니다.");
			return;
		}
    	
    	print_todo(taskList);
		System.out.print("삭제할 번호를 입력해주세요.");
		
    	while(true) { //입력된 번호가 현재 항목 번호 중에 있을 때까지 반복하게 됨 (없는 번호에 대한 오류처리) 
    		remove_no = scanner.nextInt();
			
			if(remove_no <= taskList.size() && remove_no >=1) {
				break;
			}
			else
				System.out.print("삭제할 번호를 번호를 다시 입력해주세요.");
				
			
		}
    	taskList.remove(remove_no-1);
    	for(int h=remove_no-1; h<taskList.size(); h++) { //삭제된 항목 이후의 항목들의 우선순위 1씩 감소
			taskList.get(h).setPriority(taskList.get(h).getPriority()-1);
		}
	}
	
    static public void end_todo() {
    	System.out.print("프로그램을 종료합니다.");
    }
	
}
