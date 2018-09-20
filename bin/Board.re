type t = {
  start: string,
  dest: string,
  journeys: list(Journey.t),
};

let make = (~start, ~dest, ~journeys) => {start, dest, journeys};
let toString = ({start, dest, journeys}: t): string =>
  "BOARD ---------\n"
  ++ "start: "
  ++ start
  ++ "\n"
  ++ "dest: "
  ++ dest
  ++ "\n"
  ++ "journeys: "
  ++ (List.map(Journey.toString, journeys) |> String.concat("\n"))
  ++ "\n"
  ++ "";