
let reverse l =
    let rec rev_acc acc = function
        | [] -> acc
        | hd::tl -> rev_acc (hd::acc) tl
    in 
    rev_acc [] l
;;

let rec find_element l =
    match l with 
    | [] -> 0
    | [_] -> 0
    | x::[y] -> if y < x then y else 0
    | x::y::s -> if y < x then y else find_element (y::s)
;;

let rec find_gr l a = 
    match l with 
    | [] -> -1
    | [_] -> -1
    | x::s -> 
        if x = a then -1 else
        if x < a then find_gr s a else
        let cr = (find_gr s a) in
        if cr = -1 then x else Stdlib.min (find_gr s a) x
;;

let rec find_and_replace l a b c d =
    match l with
    | [] -> []
    | [x] -> if x = a then [b] else if x = c then [d] else [x]
    | x::s -> 
        if x = a then b::find_and_replace s a b c d
        else if x = c then d::find_and_replace s a b c d
        else x::find_and_replace s a b c d
;;

let rec before l a = 
    match l with 
    | [] -> [] 
    | [x] -> if x = a then [] else [x]
    | x::s -> if x = a then [] else x::before s a
;;

let rec after l a p = 
    match l with 
    | [] -> []
    | [x] -> if x = a then [] else 
        if p = 1 then [x] else []
    | x::s -> 
        if x = a then after s a 1 else
        if p = 1 then l else
        after s a p

;;

let next_permutation l =
    let s = reverse l in
    let el = find_element s in 
    if el = 0 then None else
    let gl = find_gr s el in
    let lc = find_and_replace s el gl gl el in
    let ld = before lc gl in
    let le = reverse ld in
    let lf = after lc gl 0 in
    let lg = reverse (le @ [gl] @ lf) in
    Some lg
;;


(* don't touch the code below *)
let read_ints () =
  read_line () |> String.split_on_char ' ' |> List.rev_map int_of_string
  |> List.rev
in
let l = read_ints () in
let res = next_permutation l in 
match res with
| Some x -> x |> List.map Int.to_string |> String.concat " " |> print_endline
| None -> print_endline "None"
