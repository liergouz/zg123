
inherit BOOTS;

// ���������촦��
void create()
{
        set_name("��˿��");
        set_picid_1(8812);
        set_picid_2(8812);
        set_unit("˫");

        set_level(0);
        set_value(0);
        set_max_lasting(1099);
        set("dp", 3);
        set("pp", 3);
        set("sp", 15);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��˿��";
}
