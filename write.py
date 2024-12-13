from asammdf import MDF, Signal


def main() -> None:
    mdf = MDF()
    mdf.append(
        [
            Signal(
                samples=[1, 2, 3, 4, 5],
                timestamps=[0.0, 0.1, 0.2, 0.3, 0.4],
                name="Signal1",
                unit="A",
            ),
            Signal(
                samples=[11, 12, 13],
                timestamps=[0.0, 0.2, 0.4],
                name="Signal2",
                unit="V",
            ),
        ]
    )
    mdf.save("example.mf4", overwrite=True)


if __name__ == "__main__":
    main()
