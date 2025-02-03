
let rec gcd a b = if b = 0 then a else gcd b (a mod b) ;;
let lcm a b = a*b/(gcd a b) ;;

let rec extendList l n = if (List.length l) = n then l else l @ (extendList l (n-(List.length l))) ;;

let rec playGame la lb n = 
    if n = 0 then 0 else
    (
    match la, lb with
    | [], [] -> 0
    | x::ra, y::rb -> (
        let ad = if (x = 'R' && y = 'S') || (x = 'P' && y = 'R') || (x = 'S' && y = 'P') then 1 else 0 in
        ad + playGame ra rb (n-1)
    )
    | ((_::_, [])|([], _::_)) -> 0
    )
;;

let game l1 l2 n =
    let n1 = List.length l1 in
    let n2 = List.length l2 in
    let ntg = lcm n1 n2 in 
    let la = extendList l1 ntg in
    let lb = extendList l2 ntg in
    (playGame la lb ntg) * (n/ntg) + playGame la lb (n mod ntg)
;;


let read_l () = read_line () |> String.to_seq |> List.of_seq in
let l1 = read_l () in
let l2 = read_l () in
let n = read_int () in
game l1 l2 n |> print_int |> print_newline
