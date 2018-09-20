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
let toString = ({direction, number, time, delay, platform}: t): string =>
  "JOURNEY ---------\n"
  ++ "direction: "
  ++ direction
  ++ "\n"
  ++ "number: "
  ++ number
  ++ "\n"
  ++ "time: "
  ++ time
  ++ "\n"
  ++ "delay: "
  ++ delay
  ++ "\n"
  ++ "platform: "
  ++ platform
  ++ "\n";