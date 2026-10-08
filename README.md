# git-clone
# Điều khiển hai LED bằng một nút nhấn

Dự án PlatformIO dùng thư viện [OneButton](https://github.com/mathertel/OneButton)
để điều khiển LED tích hợp và một LED rời trên board ESP32 DOIT DevKit V1.
Chương trình không dùng `delay()`; việc nhấp nháy và đọc nút được xử lý không
chặn trong vòng lặp chính.

## Chức năng

- **Nhấn đơn:** bật/tắt LED đang được chọn.
- **Nhấn đúp:** chuyển LED được điều khiển giữa LED1 tích hợp và LED2 rời.
- **Nhấn giữ từ 800 ms:** LED đang chọn nhấp nháy, đổi trạng thái mỗi 200 ms.
- **Thả nút sau khi giữ:** dừng nhấp nháy và giữ nguyên trạng thái hiện tại của
  LED.
- OneButton xử lý nhận diện thao tác và khử rung. Nút BOOT tích hợp trên board
  (GPIO0) không được sử dụng.

## Phần cứng và nối dây

| Chức năng | ESP32 DOIT DevKit V1 | Kết nối |
| --- | ---: | --- |
| LED1 tích hợp | GPIO2 | LED tích hợp trên board, active HIGH |
| LED2 rời | GPIO25 | GPIO25 → điện trở 220–330 Ω → anode LED; cathode → GND |
| Nút điều khiển | GPIO27 | Một chân nút → GPIO27; chân còn lại → GND |

Nút dùng điện trở kéo lên nội bộ (`INPUT_PULLUP`), do đó không cần điện trở
ngoài: khi nhấn GPIO27 ở mức LOW, khi thả ở mức HIGH. Dùng chung GND của board
và test board. Không nối LED trực tiếp vào GPIO nếu chưa mắc điện trở hạn dòng.

## Cấu trúc dự án

```text
OneButton_Lib_Demo/
├── lib/
│   └── LED/
│       └── LED.h
├── src/
│   └── main.cpp
├── platformio.ini
├── README.md
└── .gitignore
```

## Build và nạp chương trình

1. Mở thư mục `OneButton_Lib_Demo` (thư mục có `platformio.ini`) trong VS Code
   với PlatformIO IDE.
2. Kết nối ESP32 DOIT DevKit V1 qua USB.
3. Chạy **Build** để biên dịch, sau đó **Upload** để nạp firmware.
4. Có thể mở Serial Monitor ở tốc độ 115200 baud.

PlatformIO tải OneButton phiên bản tương thích `^2.6.1` tự động theo khai báo
`lib_deps`. Board được cấu hình trong `platformio.ini` là
`esp32doit-devkit-v1`.
