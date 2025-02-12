# プログラム名
NAME = push_swap

# コンパイラとフラグ
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinc -Ilibft

# ディレクトリ
SRCDIR = srcs
OBJDIR = objs
LIBFTDIR = libft

# `libft` のライブラリファイル
LIBFT = $(LIBFTDIR)/libft.a

# ソースファイル
SRCS = $(SRCDIR)/main.c \
       $(SRCDIR)/commands/push.c \
       $(SRCDIR)/commands/reverse.c \
       $(SRCDIR)/commands/rotate.c \
       $(SRCDIR)/commands/swap.c \
	   $(SRCDIR)/sort/sort_three_or_less.c \
	   $(SRCDIR)/sort/sort_six_or_less.c \
	   $(SRCDIR)/sort/sort_large.c

# オブジェクトファイル
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# ヘッダファイル
HEADERS = inc/push_swap.h

# ルール
all: $(LIBFT) $(NAME)

# `push_swap` のコンパイル
$(NAME): $(OBJS) $(LIBFT) | $(OBJDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

# `libft` のコンパイル
$(LIBFT):
	make -C $(LIBFTDIR)

# `.o` ファイルの生成
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(OBJDIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# `objs` ディレクトリ作成
$(OBJDIR):
	mkdir -p $(OBJDIR)

# クリーンアップ
clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all
