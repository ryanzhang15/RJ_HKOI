let rec decrement l =
    match l with
    | [] -> l
    | x::s -> (x-1)::decrement s
;;

let rec diff l r = 
    match l with 
    | [] -> []
    | x::s -> (x-r)::diff s x
;;

let rec rl l exc = 
    match exc with
    | [] -> l
    | x::s -> (
        match l with
        | [] -> []
        | y::t -> if x = 0 then rl t s else y::rl t ((x-1)::s)
    )
;;

let exclude l exc =
    (* write your code here *)
    rl l (decrement(diff exc 0))
;;


(* don't touch the code below *)
let read_ints () =
  let line = read_line () in
  if line = ""
  then []
  else line |> String.split_on_char ' ' |> List.rev_map int_of_string |> List.rev
in
let l = read_ints () in
let exc = read_ints () in
exclude l exc |> List.map Int.to_string |> String.concat " " |> print_endline
