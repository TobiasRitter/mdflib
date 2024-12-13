from asammdf import MDF, Signal


def main() -> None:
    mdf = MDF()
    mdf.append(
        [
            Signal(
                samples=[0, 1, 2, 3, 4],
                timestamps=[0.0, 0.1, 0.2, 0.3, 0.4],
                name="Signal1",
                unit="A",
            ),
        ]
    )
    mdf.save("example.mf4")


if __name__ == "__main__":
    main()
