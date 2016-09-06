nnoremap <buffer> <F9> :w<cr>:!g++ % -O2 -o %< -std=c++11 -I ./<cr>:!./%<<cr>

colo ron
set ts=4
set nu
set autoindent
syntax enable

autocmd BufNewFile *.cpp -r ~/.template.cpp


