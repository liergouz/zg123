
// �Զ����ɣ�/make/equip/88b

inherit BOOTS;

// ���������촦��
void create()
{
        set_name("%s");
        set_picid_1(%d);
        set_picid_2(%d);
        set_unit("%s");

        set_level(%d);
        set_value(%d);
        set_max_lasting(%d);
        set("dp", %d);
        set("pp", %d);
        set("X@%%", %d);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "%s";
}
