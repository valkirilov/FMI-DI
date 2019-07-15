#include <iostream>

using namespace std;

class PC {

private:
    int cores;
    float cpu;
    int storage;
    bool network_access;
    bool power;

public:
    static int WIFI_NETWORK_CONNECTIONS;

    PC() {}

    PC(int cores, float cpu, int storage, bool network_access, bool power) {
        this->cores = cores;
        this->cpu = cpu;
        this->storage = storage;
        this->network_access = network_access;
        this->power = power;

        if (network_access) {
            WIFI_NETWORK_CONNECTIONS++;
        }
    }

    PC(const PC& pc) {
        this->cpu = pc.cpu;
        this->cores = pc.cores;
        this->storage = pc.storage;
        this->network_access = pc.network_access;
        this->power = pc.power;

        if (pc.network_access) {
            WIFI_NETWORK_CONNECTIONS++;
        }
    }

    float get_cpu() {
        return cpu;
    }

    float get_cores() {
        return cores;
    }

    void set_cores(int cores) {
        this->cores = cores;
    }

    int get_storage() {
        return this->storage;
    }

    bool get_network_access() {
        return this->network_access;
    }

    bool get_power() {
        return this->power;
    }

    void set_power(bool power) {
        this->power = power;
    }
};

int PC::WIFI_NETWORK_CONNECTIONS;

void print_pc(PC* pc) {
    cout << "CPU: " << pc->get_cores() << " cores of " << pc->get_cpu() << "GHz" << endl;
    cout << "Storage: " << pc->get_storage() << endl;
    cout << "Network Access: " << pc->get_network_access() << endl;
    cout << "Power: " << pc->get_power() << endl;
    cout << "-------------" << endl;
}

void print_wifi_connections() {
    cout << ">>> WiFi Connections: " << PC::WIFI_NETWORK_CONNECTIONS << endl;
}

int main(int argc, char** argv) {

    print_wifi_connections();

    PC default_pc = PC();
    print_pc(&default_pc);
    print_wifi_connections();

    PC custom_pc = PC(1, 2.4, 512, true, false);
    print_pc(&custom_pc);
    print_wifi_connections();

    PC copy_pc = custom_pc;

    copy_pc.set_cores(2);
    copy_pc.set_power(true);

    print_pc(&copy_pc);
    print_wifi_connections();

    return 0;
}
