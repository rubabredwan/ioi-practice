set nocompatible
filetype off

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

Plugin 'VundleVim/Vundle.vim'
Plugin 'tpope/vim-commentary'
Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'
Plugin 'dracula/vim'

call vundle#end()
filetype plugin indent on

nnoremap <buffer> <F9> :w<cr>:!g++ % -O2 -o %< -std=c++11 -I ./<cr>:!./%<<cr>

set clipboard=unnamedplus
set mouse=a
set tabstop=4
set autoindent
set shiftwidth=4
set softtabstop=4
set smarttab
set expandtab
set smartcase
set laststatus=2
set nu
set t_Co=256
set noshowmode 
syntax enable
let g:airline_theme='wombat'
let g:airline_powerline_fonts = 1
colo dracula

autocmd BufNewFile *.cpp -r ~/.template.cpp
