# Switch 宏键盘

## 概览

基于 Seeeduino XIAO 的 Switch 控制键盘。提供以下几个功能：

1. 键位自定义
2. 按键分层
3. 单发切层
4. 长按映射
5. 宏定义
6. 宏录制

用于进行用户的设置的文件均在项目的 config 目录下。其中：

- `config.h` 用于进行键盘整体属性设定；
- `key_map.h` 用于进行键盘各层的按键映射；
- `macro.h` 用于定义键盘宏。

## 设定说明

- config
  - row，键盘总行数；
  - col，键盘总列数；
  - layer，按键映射的层数；
  - rowPinList，第 1 行至最后一行分别所对应的针脚编号列表；
  - colPinList，第 1 列至最后一列分别所对应的针脚编号列表；
  - debounce，除颤阈值时长，单位是微秒。
  按钮只有在持续接通/断开至少一个除颤阈值时长之后，才会被认定为按下/松开。
  此值用来排除按钮在硬件层面上的扰动，如果发现键盘出现无源点击或者双击，可以适当增大此值。
  此值越大键盘的实时性越差。
  - holdThreshold，长按阈值时长，单位是微秒。
  如果一个按键被持续按下超过此时长，则会被认定为长按。
  - clickDelay，宏中一个 click 动作中按键按下持续的时长，单位毫秒。
  - clickEndDelay，宏中一个 click 动作结束后键盘不进行任何动作的时间，单位毫秒。
- key_map
  - `const Record *keyMap[]` 记录键盘各层的按键映射（其中可以使用的按键编码见下文）。例：

  ```cpp
  const Record exampleLayer[] = {
      PR_BTN_A, PR_BTN_B,
      PR_BTN_X, PR_BTN_Y,
  };

  const Record *keyMap[] {
      exampleLayer,
  }
  ```
- macro
  - `const MacroRecord *macroList[]` 记录用户预定义宏（其中可以使用的按键编码见下文）。例：

  ```cpp
  const MacroRecord pressAB[] = {
      PR_BTN_A,
      PR_BTN_B,
      CLICK_DELAY,
      RE_BTN_A,
      RE_BTN_B,
      END(false),
  };

  const MacroRecord *macroList[] = {
      pressAB,
  }
  ```

## 按键编码

### 通用编码

以下编码为 key_map 和 macro 文件中通用的按键编码。这些编码都对应 Switch 的一个按键，前缀共有
`PR_`、`RE_`、`CL_` 三种，分别表示按下、松开、点击（按下后快速松开，按下持续时间在 config 中设定）。
虽然在下面的表格中，这些编码并没有写前缀，但是在实际使用中，每个编码都应该加上三种前缀中的一种进行
使用。

|        编码        | 说明                                                   |
|:------------------:|:-------------------------------------------------------|
|       BTN_A        | A 键                                                   |
|       BTN_B        | B 键                                                   |
|       BTN_X        | X 键                                                   |
|       BTN_Y        | Y 键                                                   |
|       BTN_L        | L 键                                                   |
|       BTN_R        | R 键                                                   |
|       BTN_ZL       | ZL 键                                                  |
|       BTN_ZR       | ZR 键                                                  |
|     BTN_LCLICK     | 左摇杆按下                                             |
|     BTN_RCLICK     | 右摇杆按下                                             |
|    BTN_CAPTURE     | 截图键                                                 |
|      BTN_HOME      | Home 键                                                |
|     BTN_MINUS      | 减号键                                                 |
|      BTN_PLUS      | 加号键                                                 |
|         -          | -                                                      |
|   CROSS_NEUTRAL    | 松开所有方向键，此宏的 PR、RE、CL 效果相同                |
|      CROSS_UP      | 十字键上                                               |
|     CROSS_DOWN     | 十字键下                                               |
|     CROSS_LEFT     | 十字键左                                               |
|    CROSS_RIGHT     | 十字键右                                               |
|   CROSS_UP_LEFT    | 十字键上 + 左                                          |
|   CROSS_UP_RIGHT   | 十字键上 + 右                                          |
|  CROSS_DOWN_LEFT   | 十字键下 + 左                                          |
|  CROSS_DOWN_RIGHT  | 十字键下 + 左                                          |
|         -          | -                                                      |
|    CROSS_BTN_UP    | 十字键上                                               |
|   CROSS_BTN_DOWN   | 十字键下                                               |
|   CROSS_BTN_LEFT   | 十字键左                                               |
|  CROSS_BTN_RIGHT   | 十字键右                                               |
|         -          | -                                                      |
|     L_STICK_UP     | 左摇杆上                                               |
|    L_STICK_DOWN    | 左摇杆下                                               |
|    L_STICK_LEFT    | 左摇杆左                                               |
|   L_STICK_RIGHT    | 左摇杆右                                               |
| L_STICK_FREE(x, y) | 左摇杆方向自定义，x/y 范围为 0（最左/下） 到 255（最右/上） |
|         -          | -                                                      |
|     R_STICK_UP     | 右摇杆上                                               |
|    R_STICK_DOWN    | 右摇杆下                                               |
|    R_STICK_LEFT    | 右摇杆左                                               |
|   R_STICK_RIGHT    | 右摇杆右                                               |
| R_STICK_FREE(x, y) | 右摇杆方向自定义，x/y 范围为 0（最左/下） 到 255（最右/上） |

---

### 仅在 macro 中使用的编码

|      编码       | 说明                                                                       |
|:---------------:|:-------------------------------------------------------------------------|
|   DELAY(time)   | 休止 time 时长，单位 ms。                                                    |
|   CLICK_DELAY   | 休止键盘设定中的 clickDelay 的时长                                         |
| CLICK_END_DELAY | 休止键盘设定中的 clickEndDelay 的时长                                      |
|  END(isRepeat)  | 标示宏结束，宏必须以此结尾。isRepeat 为 true 或 false，表示宏是否需要循环播放 |

--- 

### 仅在 key_map 中使用的编码

|        编码         | 说明                                                                    |
|:-------------------:|:------------------------------------------------------------------------|
|   HOLD(tap, hold)   | 设定按键点按和长按时的编码，tap 和 hold 分别为 HOLD 之外的编码           |
|        EMPTY        | 没有任何行为，表示一个按键的功能为空                                     |
|    MACRO(index)     | 回放索引为 index 的宏，宏索引从 0 开始                                   |
|    MACRO_RECORD     | 非录制状态下，开始宏录制；否则结束录制，将新录制的宏标记为非循环宏         |
|  MACRO_RECORD_LOOP  | 非录制状态下，开始宏录制；否则结束录制，将新录制的宏标记为循环宏           |
| MACRO_PLAY_RECORDED | 播放录制的宏                                                            |
|                     |                                                                         |
|      ML(layer)      | 临时切换到层 layer，按键松开后回到之前所在的层                           |
|     OSL(layer)      | 单发切层，此键后的下一键会使用 layer 层的映射。下个键按下后，切层会解除    |
|      TL(layer)      | 切换 layer 层的开关。切层后若不再按下 TL(layer)，键盘会尽量留在 layer 层。 |
|     DFL(layer)      | 设定键盘的默认层为 layer。在没有切换层时，键盘都会留在默认层。             |
 