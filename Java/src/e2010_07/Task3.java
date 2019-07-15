package e2010_07;

public class Task3 {

	public static void printPC(PC pc) {
		System.out.println("CPU: " + pc.getCores() + " cores of " + pc.getCPU() + "GHz");
		System.out.println("Storage: " + pc.getStorage());
		System.out.println("Network Access: " + pc.getNetworkAccess());
		System.out.println("Power: " + pc.getPower());
		System.out.println("-------------");
	}

	public static void printWifiConnectedDevices() {
		System.out.println(">>> WiFi Connected Devices: " + PC.WIFI_CONNECTED_DEVICES);
	}

	public static void main(String[] args) {

		printWifiConnectedDevices();

		PC defaultPC = new PC();
		printPC(defaultPC);
		printWifiConnectedDevices();

		PC customPC = new PC(1, 2.7, 512, true, true);
		printPC(customPC);
		printWifiConnectedDevices();

		PC copyPC = new PC(customPC);
		printWifiConnectedDevices();

		copyPC.setPower(false);

		printPC(copyPC);
		printWifiConnectedDevices();

	}

}
