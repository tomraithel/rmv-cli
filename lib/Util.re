open Lwt;

open LTerm_style;

open LTerm_text;

open PrintBox;

let hello = () =>
  LTerm.printls(
    eval([
      B_fg(red),
      S("Hello,"),
      E_fg,
      S(" "),
      B_fg(green),
      S("World!"),
      E_fg,
    ]),
  );

let table = (data: array(array(string))) => {
  /* let square = n =>
     Array.init(n, i => Array.init(n, j => PrintBox.sprintf("(%d,%d)", i, j)))
     |> PrintBox.grid; */

  let headers = [|
    PrintBox.sprintf(" Ziel "),
    PrintBox.sprintf(" Zug "),
    PrintBox.sprintf(" Abfahrt (Delay) "),
    PrintBox.sprintf(" Gleis "),
  |];

  let rowToPrintBox = row =>
    Array.map((s: string) => PrintBox.text(" " ++ s ++ " "), row);

  let printboxData = Array.map(rowToPrintBox, data);
  let t = Array.concat([[|headers|], printboxData]) |> PrintBox.grid;

  let sq = t |> PrintBox.frame;

  PrintBox_text.output(stdout, sq);
};