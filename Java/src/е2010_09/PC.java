package е2010_09;

public class PC {

	private int cores;
	int memory;
	private boolean power;
	
	static int CREATED_PCS = 0;
	
	PC() {
		this.cores = 0;
		this.memory = 0;
		this.power = false;
		
		PC.CREATED_PCS++;
	}
	
	PC(int cores, int memory, boolean power) {
		this.cores = cores;
		this.memory = memory;
		this.power = power;
		
		CREATED_PCS++;
	}
	
	PC(PC pc) {
		this.cores = pc.cores;
		this.memory = pc.memory;
		this.power = pc.power;
		
		CREATED_PCS++;
	}
	
	public int getCores() {
		return this.cores;
	}
	
	public void setCores(int cores) {
		this.cores = cores;
	}
	
	public boolean getPower() {
		return this.power;
	}
	
	public void setPower(boolean power) {
		this.power = power;
	}
	
	public static void printPC(PC pc) {
		System.out.println("Cores: " + pc.getCores() + "; Memory: " + pc.memory + "; Power: " + pc.getPower());
	}
	
	public static void printCreatedPCs() {
		System.out.println(">>> Created PCs: " + PC.CREATED_PCS);
	}
	
	public static void main(String[] args) {
		
		printCreatedPCs();
		
		PC defaultPC = new PC();
		printPC(defaultPC);
		
		printCreatedPCs();
		
		PC customPC = new PC(1, 128, false);
		printPC(customPC);
		
		printCreatedPCs();
		
		PC copyPC = new PC(customPC);
		printPC(copyPC);
		
		copyPC.setCores(3);
		copyPC.setPower(true);
		printPC(customPC);
		printPC(copyPC);
		
		printCreatedPCs();

	}

}
