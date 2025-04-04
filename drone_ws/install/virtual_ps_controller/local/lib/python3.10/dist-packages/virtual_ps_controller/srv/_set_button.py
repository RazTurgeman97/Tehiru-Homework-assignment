# generated from rosidl_generator_py/resource/_idl.py.em
# with input from virtual_ps_controller:srv/SetButton.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SetButton_Request(type):
    """Metaclass of message 'SetButton_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('virtual_ps_controller')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'virtual_ps_controller.srv.SetButton_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_button__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_button__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_button__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_button__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_button__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetButton_Request(metaclass=Metaclass_SetButton_Request):
    """Message class 'SetButton_Request'."""

    __slots__ = [
        '_button_id',
        '_pressed',
    ]

    _fields_and_field_types = {
        'button_id': 'uint8',
        'pressed': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.button_id = kwargs.get('button_id', int())
        self.pressed = kwargs.get('pressed', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.button_id != other.button_id:
            return False
        if self.pressed != other.pressed:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def button_id(self):
        """Message field 'button_id'."""
        return self._button_id

    @button_id.setter
    def button_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'button_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'button_id' field must be an unsigned integer in [0, 255]"
        self._button_id = value

    @builtins.property
    def pressed(self):
        """Message field 'pressed'."""
        return self._pressed

    @pressed.setter
    def pressed(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'pressed' field must be of type 'bool'"
        self._pressed = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SetButton_Response(type):
    """Metaclass of message 'SetButton_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('virtual_ps_controller')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'virtual_ps_controller.srv.SetButton_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_button__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_button__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_button__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_button__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_button__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetButton_Response(metaclass=Metaclass_SetButton_Response):
    """Message class 'SetButton_Response'."""

    __slots__ = [
        '_success',
        '_message',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'message': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.message = kwargs.get('message', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        if self.message != other.message:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value


class Metaclass_SetButton(type):
    """Metaclass of service 'SetButton'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('virtual_ps_controller')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'virtual_ps_controller.srv.SetButton')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__set_button

            from virtual_ps_controller.srv import _set_button
            if _set_button.Metaclass_SetButton_Request._TYPE_SUPPORT is None:
                _set_button.Metaclass_SetButton_Request.__import_type_support__()
            if _set_button.Metaclass_SetButton_Response._TYPE_SUPPORT is None:
                _set_button.Metaclass_SetButton_Response.__import_type_support__()


class SetButton(metaclass=Metaclass_SetButton):
    from virtual_ps_controller.srv._set_button import SetButton_Request as Request
    from virtual_ps_controller.srv._set_button import SetButton_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
