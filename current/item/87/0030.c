
// �Զ����ɣ�/make/equip/87b

inherit WAIST;

// ���������촦��
void create()
{
        set_name("��Ƥ��");
        set_picid_1(8703);
        set_picid_2(8703);
        set_unit("��");

        set_level(30);
        set_value(1350);
        set_max_lasting(4899);
        set("dp", 5);
        set("pp", 5);
        set("hp%", 8);
        set("mp%", 8);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��Ƥ��";
}
