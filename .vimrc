" nvim-dap configuration {{{
if has('nvim')
lua << EOF
local dap = require('dap')
dap.configurations = {
  omrdemonstrator = {
    type = 'cpp';
    request = 'launch';
    name = "omr-demonstrator";
    program = "./install/bin/omr-demonstrator";
    args = {};
    cwd = "./samples";
    env = function()
        local variables = {}
        for k, v in pairs(vim.fn.environ()) do
            table.insert(variables, string.format("%s=%s", k, v))
        end
        return variables
    end,
  },
}
EOF
  nnoremap <silent> <F5> :lua require'dap'.run(require'dap'.configurations.omrdemonstrator);require'dap'.repl.open()<CR>
  nnoremap <silent> <F6> :lua require'dap'.continue()<CR>
  nnoremap <silent> <F7> :lua require'dap'.step_over()<CR>
  nnoremap <silent> <F8> :lua require'dap'.step_into()<CR>
  nnoremap <silent> <F9> :lua require'dap'.step_out()<CR>
  nnoremap <silent> <leader>db :lua require'dap'.toggle_breakpoint()<CR>
  nnoremap <silent> <leader>dB :lua require'dap'.toggle_breakpoint(vim.fn.input('Breakpoint condition: '))<CR>
endif
" }}}

" AsyncRun AsyncTasks configuration {{{
nnoremap <silent> <F3> :AsyncTask build-install<CR>
nnoremap <silent> <F4> :AsyncTask build-test<CR>
" }}}
