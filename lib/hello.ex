defmodule Hello do
  @on_load :init

  def init do
    path = Application.app_dir(:nif_playground, "priv/hello") |> String.to_char_list
    :ok = :erlang.load_nif(path, 0)
  end

  def ints() do
    exit(:nif_not_loaded)
  end
end
