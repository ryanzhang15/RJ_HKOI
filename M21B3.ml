let rec toggle l =
    match l with
    | [] -> []
    | [_] -> l
    | x::y::s -> x::-y::toggle s
;;


(* don't touch the code below *)
let read_ints () =
  let line = read_line () in
  if line = ""
  then []
  else line |> String.split_on_char ' ' |> List.rev_map int_of_string |> List.rev
in
let l = read_ints () in
toggle l |> List.map Int.to_string |> String.concat " " |> print_endline
