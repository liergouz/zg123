
// �Զ����ɣ�/make/equip/88b

inherit BOOTS;

// ���������촦��
void create()
{
        set_name("��Ь");
        set_picid_1(8804);
        set_picid_2(8804);
        set_unit("˫");

        set_level(40);
        set_value(2200);
        set_max_lasting(6699);
        set("dp", 10);
        set("pp", 10);
        set("X@%", 7);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��Ь";
}
