
// �Զ����ɣ�/make/equip/88b

inherit BOOTS;

// ���������촦��
void create()
{
        set_name("Ƥѥ");
        set_picid_1(8805);
        set_picid_2(8805);
        set_unit("˫");

        set_level(50);
        set_value(2800);
        set_max_lasting(7299);
        set("dp", 12);
        set("pp", 12);
        set("X@%", 7);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "Ƥѥ";
}
