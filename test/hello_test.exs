defmodule HelloTest do
  use ExUnit.Case

  test "ints" do
    assert 1 = Hello.ints()
  end
end
