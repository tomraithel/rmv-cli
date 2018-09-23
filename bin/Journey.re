type t = {
  direction: string,
  number: string,
  time: string,
  delay: string,
  platform: string,
};

let make = (~direction, ~number, ~time, ~delay, ~platform): t => {
  direction,
  number,
  time,
  delay,
  platform,
};

let toArray = ({direction, number, time, delay, platform}: t): array(string) => [|
  direction,
  number,
  time ++ " Uhr (" ++ delay ++ " min)",
  platform,
|];