
// �Զ����ɣ�/make/equip/87b

inherit WAIST;

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(8704);
        set_picid_2(8704);
        set_unit("��");

        set_level(40);
        set_value(1850);
        set_max_lasting(6099);
        set("dp", 6);
        set("pp", 6);
        set("hp%", 9);
        set("mp%", 9);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
