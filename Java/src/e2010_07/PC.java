package e2010_07;

public class PC {

	private int cores;
	private double cpu;
	private int storage;
	private boolean networkAccess;
	private boolean power;
	
	public static int WIFI_CONNECTED_DEVICES;
	
	PC() {
		cores = 0;
		cpu = 0;
		storage = 0;
		networkAccess = false;
		power = false;
	}
	
	PC(int cores, double inputCPU, int storage, boolean networkAccess, boolean power) {
		this.cores = cores;
		cpu = inputCPU;
		this.storage = storage;
		this.networkAccess = networkAccess;
		this.power = power;
		
		if (networkAccess && power) {
			WIFI_CONNECTED_DEVICES++;
		}
	}
	
	PC(PC pc) {
		this.cores = pc.cores;
		this.cpu = pc.cpu;
		this.storage = pc.storage;
		this.networkAccess = pc.networkAccess;
		this.power = pc.power;
		
		if (pc.networkAccess && pc.power) {
			WIFI_CONNECTED_DEVICES++;
		}
	}
	
	public int getCores() {
		return cores;
	}
	
	
	public double getCPU() {
		return cpu;
	}
	
	public int getStorage() {
		return this.storage;
	}
	
	public boolean getNetworkAccess() {
		return networkAccess;
	}
	
	public boolean getPower() {
		return power;
	}
	
	public void setPower(boolean power) {
		this.power = power;
		
		if (!power && this.networkAccess) {
			WIFI_CONNECTED_DEVICES--;
		}
	}
	
}
