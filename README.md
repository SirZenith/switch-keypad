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
  - **row**，键盘总行数；
  - **col**，键盘总列数；
  - **layer**，按键映射的层数；
  - **rowPinList**，第 1 行至最后一行分别所对应的针脚编号列表；
  - **colPinList**，第 1 列至最后一列分别所对应的针脚编号列表；
  - **debounce**，除颤阈值时长，单位是微秒。
  按钮只有在持续接通/断开至少一个除颤阈值时长之后，才会被认定为按下/松开。
  此值用来排除按钮在硬件层面上的扰动，如果发现键盘出现无源点击或者双击，可以适当增大此值。
  此值越大键盘的实时性越差。
  - **holdThreshold**，长按阈值时长，单位是微秒。
  如果一个按键被持续按下超过此时长，则会被认定为长按。
  - **clickDelay**，宏中一个 click 动作中按键按下持续的时长，单位毫秒。
  - **clickEndDelay**，宏中一个 click 动作结束后键盘不进行任何动作的时间，单位毫秒。
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
|          -          | -                                                                       |
|      ML(layer)      | 临时切换到层 layer，按键松开后回到之前所在的层                           |
|     OSL(layer)      | 单发切层，此键后的下一键会使用 layer 层的映射。下个键按下后，切层会解除    |
|      TL(layer)      | 切换 layer 层的开关。切层后若不再按下 TL(layer)，键盘会尽量留在 layer 层。 |
|     DFL(layer)      | 设定键盘的默认层为 layer。在没有切换层时，键盘都会留在默认层。             |
 
## 层

切层可以让键数不多的键盘更加实用。比如下面的按键映射：

```cpp
const Record crossLayer[] = {
    MO(1)        , PR_CROSS_UP  , MACRO(0)      ,
    PR_CROSS_LEFT, PR_CROSS_DOWN, PR_CORSS_RIGHT,
};

const Record functionLayer[] {
    EMPTY, PR_BTN_X, PR_BTN_A,
    EMPTY, PR_BTN_Y, PR_BTN_B,
};

const Record *keyMap[] {
    exampleLayer,
    functionLayer,
}
```

在层 0，映射布置了 4 个方向键盘，同时在左上角放置了切换到层 1 的编码。
那么在需要时，用户只需要按下左上的按键，就可以在键盘的右部触发 A、B、X、Y 四个编码。 

切换层相关的编码有 `ML(x)`、`OSL(x)`、`TL(x)`、`DFL(x)`。x 为层编号，层的编号是从 0 开始的。
可以使用的层编号为 0 到 31。

- 在键盘启动时，所有的层都是处于非激活状态。
- `ML(x)` 在被按下时，层 x 会被激活；
- `TL(x)` 被按下时，层 x 如果是非激活状态，则层 x 会被激活；反之层 x 会变为非激活。
- `OSL(x)` 被按下后，层 x 保持激活直到下一个按键被按下。在新按键被按下后，层 x 变为非激活。
- 在所有层都处于非激活态时，键盘将会停留在默认层，初始的默认层是层 0，
  `DFL(x)` 可以将默认层变为 x。

当有多个层同时处于活跃状态时，键盘会采用各活跃层中编号最大的一层作为当前使用的层，
在设置按键映射的时候请注意这一点。

## 宏

被赋予 `MACRO(x)` 编码的按键会在被按下时，回放编号为 x 的宏，需要注意的是，宏的编号从 1 开始。
在宏播放的过程中，再次按下触发宏播放的按键即可终止宏播放；
同时，在宏播放的过程中，所有其他按键的功能都会被屏蔽。

例如，用户在第 2 层的第 2 行第 3 列放置了宏 0 的触发码，
并通过按下切层按键之后按下宏 0 键进行宏回放；
若想要终止回放，用户只需再次按下第 2 行第 3 列的按键，而不需要为此再按下切层键。

所有在 macro.h 中定义的宏都需要使用 `END` 编码来结尾。
这一编码需要指定一个参数，用于决定宏在回放完一次之后是否需要自动从头再播放。

`END(true)` 表示宏需要循环；`END(false)` 则表示不循环。

除了在 macro.h 定义宏之外，键盘还提供了一个槽位用于在运行状态下手动录制宏（也只提供了一个录制位）。
录制位默认的长是 400 单位。

用户每次按下、松开按钮都会占用一个单位，
记录按钮被按下后持续的时间，以及松开按钮到下一次再有按钮被按下也各需要占用一个单位。
但是如果按下的按钮是起切层的作用，则不需要占用录制单位。

也就是说默认的录制宏长度大概是能记录用户的 100 次操作——因为通常的操作是按下按钮、持续、松开按钮、
侍机 4 个为一组出现。

如果在设定中指定了红色 LED 对应的针脚，那么在录制开始时，红色 LED 会亮起。
随着剩余录制长度的减少，红灯会由常亮向快速闪烁逐渐变化。
在录制长度达到上限时，红灯会完全熄灭。

用户可以通过 `MACRO_RECORD` 和 `MACRO_RECORD_LOOP` 两个编码中的任何一个发起录制，
这两个编码在发起录制的方面没有任何功能上的区别，两者在录制状态下被再次按下时，也都会结束录制。
如果使用 `MACRO_RECORD` 结束录制，得到的宏则是非循环的；`MACRO_RECORD_LOOP` 结束录制则会得
到循环宏。

录制完成后，按下 `MACRO_PLAY_RECORDED` 键就可以播放录制槽位之中记录的宏。
