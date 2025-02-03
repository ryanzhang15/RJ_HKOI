let rec generate n = 
    (* write your code here *)
    if n = 1 then "a"
    else
        let a = char_of_int(n+96) in
        let b = String.make 1 a in
        generate (n-1) ^ b ^ generate (n-1) 
;;


(* don't touch the code below *)
read_int () |> generate |> print_endline
