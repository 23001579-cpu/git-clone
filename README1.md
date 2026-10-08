# Platform IO: Libraries Usage Demo 
By Nguyễn Anh Tuấn

_Dùng cho lớp "Phát triển ứng dụng IoT" tại khoa Vật lý - HUS_

## Mục đích 

Minh chứng trực quan việc sử dụng môi trường phát triển tích hợp PlatformIO. Trong việc:
- Sử dụng thư viện tự phát triển (user library) 
- Sử dụng thư viện mã mở có sẵn từ cộng đồng (hoặc bên thứ ba)
- Phát triển mã thống nhất cho dự án sử dụng đa nền tảng phần cứng
- Trực quan hóa các bước làm việc, và thao tác trên nền tảng PlatformIO cho phát triển firmware.

## Phần cứng 
Trong dự án demo này, tôi sử dụng hai board phát triển
1. ESP32 Devkit v1:
    - Con chip ESP32 kiến trúc xtensa, lõi kép
    - Tích hợp Blue LED vào chân GPIO02, active level = HIGH 
    - Tích hợp nút bấm (BOOT) vào chân GPIO00, active level = LOW
    - SV nên: Tra cứu và xem schematic của board này để xem chi tiết.

2. ESP32-C3 Super Mini:
    - Con chip ESP32-C3, kiến trúc RISCV, lõi đơn 
    - Tích hợp Blue LED vào chân GPIO08, active level = LOW
    - Tích hợp nút bấm (BOOT) chân GPIO09, active level = LOW 
    - SV có thể: Tra cứu và xem schematic của board này để xác nhận các phần cứng trên.

## Yêu cầu chức năng của `PushBTN_User_Lib_Demo`
Chức năng chung của dự án này, khá đơn giản nhưng để làm tốt thì cần mức độ chuyên nghiệp nhất định. Dự án này cũng minh họa cách tổ chức mã, cách viết mã sạch trong C++. 

Yêu cầu viết chương trình có chức năng sau:
    + bấm nút một lần (single click) để bật/tắt LED (đảo trạng thái). 
    + nhấn giữ >2s (hold) thì LED sẽ chuyển sang trạng thái nhấp nháy liên tục (blink 200ms một lần)
    + nếu tiếp tục nhấn single click thì LED lại chuyển trạng thái bật/tắt 
    + Lưu ý: khử rung phím bấm 

## Các dự án trong `workspace` này

- `C3_SuperMini_Blink`: ví dụ Blink với PlatformIO, dùng LED rời trên GPIO4
  (không dùng LED tích hợp trên board).
- Sử dụng thư viện tự viết (user libraries) để đạt chức năng nói trên, xem chi tiết trong thư mục dự án `PushBTN_User_Lib_Demo`.
- `OneButton_Lib_Demo`: dùng một nút ngoài với thư viện OneButton để chọn và
  điều khiển LED tích hợp hoặc LED rời: nhấn đơn bật/tắt LED đang chọn, nhấn đúp
  chuyển LED, nhấn giữ làm LED đó nhấp nháy. Xem `OneButton_Lib_Demo/README.md`.

**Lưu ý**: Sinh viên có thể (và nên) `git clone <đường dẫn>` repo này về máy cá nhân để biên dịch, chạy thử, và có thể thử nghiệm, phát triển thêm các ý tưởng riêng của mình dựa trên hướng dẫn.
