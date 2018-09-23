type t = {
  start: string,
  dest: string,
  journeys: list(Journey.t),
};

let make = (~start, ~dest, ~journeys) => {start, dest, journeys};

let toArray = ({start, dest, journeys}: t): array(array(string)) =>
  Array.map(Journey.toArray, Array.of_list(journeys));