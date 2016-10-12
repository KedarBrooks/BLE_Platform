*
Southwest_LifeJacket_Firmware-LJ2 
Version : 1.2  
By: Kedar Brooks
*/ 

#include <BLE-API.h>

#define DEVICE_NAME         "LJ A002 2020 GOOD"
#define DEVICE_NAME_ALERT   "LJ A002 2002 ALERT"
#define TXRX_BUF_LEN        20 
// Create ble instance 
BLE                         ble;
// Create timer task 
Ticker                      ticker1s; 

// The UUID of service and characteristics 
static const unit8_t service1_uuod[]        = {0x71, 0x3D, 0, 0, 0x50, 0x3E, 0x4C, 0x75, 0xBA, 0x94, 0x31, 0x48, 0xF1, 0x8D, 0x94, 0x1E}; 
static const unit8_t service1_chars1_uuid[] = 
static const uint8_t service1_chars2_uuid[] = 
static const uint8_t service1_chars3_uuid[] = 
// Used in advertisment 
static const uint8_t uart_base_uuid_rev[]   = 

// Init value of chars 
uint8_t chars1_value[TXRX_BUF_LEN] = {0}; 
uint8_t chars2_value[TXRX_BUF_LEN] = {1,2,3};
uint8_t chars3_value[TXRX_BUF_LEN] = {0}; 

// Create characteristics 
GetCharacteristics characteristics(service1_chars1_uuid, chars1_value, 1, TXRX_BUF_LEN, GattCharacteristic::BLE_GATT_CHAR_PROPERTIES_WRITE | GattCharacteristic::BLE_GATT_CHAR_PROPERTIES_WRITE_WITCHOUT_RESPONSE ); 
GattCharacteristic characteristics(service1_chars2_uuid, chars2_value, 3, TXRX_BUF_LEN)
GattCharacteristic  characteristic3(service1_chars3_uuid, chars3_value, 1, TXRX_BUF_LEN, GattCharacteristic::BLE_GATT_CHAR_PROPERTIES_NOTIFY);
GattCharacteristic *uartChars[] = {&characteristic1, &characteristic2, &characteristic3};
//Create service
GattService         uartService(service1_uuid, uartChars, sizeof(uartChars) / sizeof(GattCharacteristic *));

HeartRateService         *hrService;
DeviceInformationService *deviceInfo;
// Init HRM to 100bps
static uint8_t hrmCounter = 100; 

void disconnectionCallBack(const Gap::disconnectionCallBackParams_t *params) { 
    Serial.print("Disconnected hande : "); 
    Serial.print(params->handle, HEX);
    Serial.print("Disconnected reason:");
    Serial.print(params->reason, HEX); 
    Serial.print("Restart advertising"); 
    ble.startAdvertising();   
}

void connectionCallBack( const Gap::connectionCallBackParams_t *params ) { 
    uint8_t index; 
    if(params->role == Gap::PERIPHERAL) { 
        Serial.println("Peripheral "); 
    }

    Serial.print("The conn handle : "); 
    Serial.print(params_>handle, HEX); 
    Serial.print("The conn role : "); 
    Serial.print(params->role, HEX);
    
    Serial.print("The peerAddr type : ");
    Serial.print(params->peerAddrType, HEX);
    Serial.print(" The peerAddr : ");
    for(index=0; index<6; index++) { 
        Serial.print(params_peerAddr[index], HEX); 
        Serial.print(" ");
            }      
}
