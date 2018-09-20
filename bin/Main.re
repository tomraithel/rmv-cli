open Soup;

let soup = read_file("./example/departure.xml") |> parse;
/* let name = soup $$ "HafasName" |> iter;
   R.leaf_text; */

let start = "Start HafasName" |> ($)(soup) |> R.leaf_text;
let dest = "Dest HafasName" |> ($)(soup) |> R.leaf_text;
let mainStop = journey => journey $ "MainStop";

let journeyDirection = journey =>
  journey
  $ "Attribute[type=\"DIRECTION\"] AttributeVariant[type=\"NORMAL\"]"
  |> R.leaf_text;
let journeyNumber = journey =>
  journey
  $ "Attribute[type=\"NUMBER\"] AttributeVariant[type=\"NORMAL\"]"
  |> R.leaf_text;

let journeyTime = journey => mainStop(journey) $ "Time" |> R.leaf_text;
let journeyDelay = journey => mainStop(journey) $ "Delay" |> R.leaf_text;

let journeyPlatform = journey =>
  mainStop(journey) $ "Platform" |> R.leaf_text;

let journeys =
  soup
  $$ "Journey"
  |> to_list
  |> List.map(j =>
       Journey.make(
         ~direction=journeyDirection(j),
         ~number=journeyNumber(j),
         ~platform=journeyPlatform(j),
         ~time=journeyTime(j),
         ~delay=journeyDelay(j),
       )
     );

let board = Board.make(~start, ~dest, ~journeys);

print_endline(Board.toString(board));