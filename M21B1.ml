let rec count n = 
  (* write your code here *)
  if n = 1 then 1
  else if n mod 2 = 1 then 1 + count (3*n+1)
  else 1 + count (n/2)
;;


(* don't touch the code below *)
read_int () |> count |> print_int |> print_newline
