
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("����ñ");
        set_picid_1(6536);
        set_picid_2(6536);

        set_level(40);
        set_value(9000);
        set_max_lasting(6699);
        set("dp", 37);
        set("pp", 27);

        setup();

        set_gender(1);
        set_head_code(43);
}

// ��������ȡ����
string get_desc()
{
        return "����ñ";
}
