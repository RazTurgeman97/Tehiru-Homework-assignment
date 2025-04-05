from setuptools import find_packages
from setuptools import setup

setup(
    name='liftoff_utils',
    version='0.0.0',
    packages=find_packages(
        include=('liftoff_utils', 'liftoff_utils.*')),
)
