# get_next_line

42 Tokyo のプロジェクト課題です。ファイルディスクリプタから1行ずつ読み込む関数 `get_next_line` を C 言語で実装しています。

---

## 目的

標準ライブラリの `getline` などを使わずに、`read` システムコールのみを用いてファイルや標準入力から1行ずつ文字列を取得する関数を自作することを目的としています。  
静的変数を活用してバッファを持続させ、複数回の呼び出しにまたがって正しく動作するよう設計されています。

---

## 関数仕様

```c
char *get_next_line(int fd);
```

- **引数**: ファイルディスクリプタ `fd`
- **戻り値**: 読み込んだ1行（改行文字 `\n` を含む）。EOF または エラー時は `NULL`
- **BUFFER_SIZE**: コンパイル時に `-D BUFFER_SIZE=n` で変更可能（デフォルト: `40`）

---

## ディレクトリ構成

```
get_next_line/
├── get_next_line/                   # 提出用ソースコード
│   ├── get_next_line.h              # 標準版ヘッダファイル
│   ├── get_next_line.c              # 標準版メイン実装
│   ├── get_next_line_utils.c        # 標準版ユーティリティ関数群
│   ├── get_next_line_bonus.h        # ボーナス版ヘッダファイル
│   ├── get_next_line_bonus.c        # ボーナス版メイン実装（複数fd対応）
│   ├── get_next_line_utils_bonus.c  # ボーナス版ユーティリティ関数群
│   └── gnlTester/                   # テスト用ディレクトリ
│
└── failed_get_next_line/            # 開発過程の試行実装（参考用）
```

---

## ファイル詳細

### 標準版（`get_next_line.c` / `get_next_line_utils.c`）

単一のファイルディスクリプタに対して1行ずつ読み込む実装です。  
静的変数 `buffer` にファイルの読み込み残りを保持します。

| 関数名 | 役割 |
|--------|------|
| `get_next_line` | メイン関数。fd から1行を返す |
| `read_file` | `read` を繰り返し呼び出し、改行まで読み込む |
| `ft_line` | バッファから1行分の文字列を切り出す |
| `ft_next` | 返した行以降のバッファ残りを返す |
| `ft_free` | バッファを結合して古いバッファを解放する |

### ボーナス版（`get_next_line_bonus.c` / `get_next_line_utils_bonus.c`）

標準版との違いは、`static char *buffer[OPEN_MAX]` を使うことで **複数のファイルディスクリプタを同時に管理** できる点です。  
ゲーム中にプレイヤーが複数ファイルを交互に読み込むようなユースケースに対応しています。

### ユーティリティ関数（`get_next_line_utils.c` / `get_next_line_utils_bonus.c`）

| 関数名 | 役割 |
|--------|------|
| `ft_strlen` | 文字列の長さを返す |
| `ft_strchr` | 文字列内の指定文字を検索する |
| `ft_strjoin` | 2つの文字列を結合して新しい文字列を返す |
| `ft_calloc` | ゼロ初期化済みのメモリを確保する |
| `ft_bzero` | メモリ領域をゼロクリアする |

---

## 動作の流れ

```
get_next_line(fd)
    │
    ├─ read_file(fd, buffer)
    │       │
    │       └─ read() を BUFFER_SIZE バイトずつ繰り返し
    │          ├─ 読み込んだデータを既存バッファに結合 (ft_strjoin)
    │          └─ 改行 '\n' が見つかったら読み込みを停止
    │
    ├─ ft_line(buffer)   → 改行までを1行として切り出して返す
    │
    └─ ft_next(buffer)   → 改行以降をバッファに残す（次回呼び出し用）
```

---

## コンパイル例

```bash
# 標準版
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl

# ボーナス版
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```

---

## 作者

**dkajiwar** — 42 Tokyo student
