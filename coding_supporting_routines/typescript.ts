// generating random numbers
getRandomInteger(min, max)
{
  console.log("getRandomInteger");
  return Math.floor(Math.random() * (max - min) + min);
}
