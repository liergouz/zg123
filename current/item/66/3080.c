
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("������ñ");
        set_picid_1(6638);
        set_picid_2(6638);

        set_level(80);
        set_value(26000);
        set_max_lasting(13899);
        set("dp", 104);
        set("pp", 46);

        setup();

        set_gender(2);
        set_head_code(56);
}

// ��������ȡ����
string get_desc()
{
        return "������ñ";
}
